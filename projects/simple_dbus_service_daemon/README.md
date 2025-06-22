# D-Bus Daemon (Gio/GDBus)

A minimal D-Bus service implemented using GLib's Gio (GDBus) library, demonstrating how to expose a simple method to add & subtract two numbers. This project focuses on clarity and adherence to D-Bus principles, including proper introspection.

**Note:** 
- The **Add** method is exposed manually using a custom `GDBusInterfaceVTable` and a single `g_dbus_connection_register_object()` call. 
- In contrast, the **Sub** method is defined in its own D-Bus interface and implemented via the auto-generated `ComMpunixDaemonSub` skeleton (produced by `gdbus-codegen`). where you instantiate the skeleton, export it on the bus, and connect your handler to its `"handle-sub"` signal.

## Features

  * **D-Bus Service Name:** `com.mpunixDaemon`
  * **Object Path:** `/com/mpunixDaemon`
  * **Interface:** `com.mpunixDaemon.Add & com.mpunixDaemon.Sub`
  * **Method:** `Add & sub`
  * **Introspection:** Fully supports `gdbus introspect` for service discovery.
  * **Session Bus:** Registers on the D-Bus session bus.

>Q:Why are there two interfaces
- `com.mpunixDaemon.Add` is implemented using `g_dbus_connection_register_object` to understnad how to manually invoke handlers and custom implementaions.
- `com.mpunixDaemon.Sub` is implemeneted using `gdbus-codegen`, using the objects and export skeleton interface provided by the auto generated code.

```bash
                        ┌────────────────┐
                        │  Session Bus   │
                        └────────────────┘
                                │
              register_object→  │  ← register_object
        (Interface, add_vtable) │  (Interface, skeleton)
                                ▼
                    /com/mpunixDaemon object
                        • com.mpunixDaemon.Add.Add # perform addition
                        • com.mpunixDaemon.Sub.Sub # perform subtraction
```

## Building

```bash
make build
```

## Running the Daemon

start the daemon in your terminal:

```bash
make run
```

You should see output similar to:

```
$ make run
stdbuf -oL ././build/simple_dbus_service_daemon | tee ./log/simple_dbus_service_daemon.log
[INFO]: g_main_loop_run is invoked
...
[INFO]: Bus name acquired, daemon active..
```

## Interacting with the Daemon

While the daemon is running in one terminal, open a new terminal to interact with it using `gdbus`.

### 1\. Call the `Add` or `Sub` Method

Invoke the `Add` method with two integer arguments:

```bash
gdbus call --session 
    --dest com.mpunixDaemon 
    --object-path /com/mpunixDaemon 
    --method com.mpunixDaemon.Add.Add # or com.mpunixDaemon.Sub.Sub 
    10 20
```

**Expected Output:**

```
(30,)
```

### 2\. Introspect the Daemon

Discover the methods and interfaces exposed by the daemon:

```bash
gdbus introspect 
    --session 
    --dest com.mpunixDaemon 
    --object-path /com/mpunixDaemon
```

### 3\. Monitor D-Bus Traffic

See the D-Bus messages exchanged between `gdbus` and your daemon:

```bash
gdbus monitor --session --dest com.mpunixDaemon
```

Now, try running the `gdbus call` command again in another terminal, and you'll see the method call and reply messages appear in the `gdbus monitor` terminal.

## Design Notes

This daemon is designed to be straightforward:

  * It owns a well-defined D-Bus service name and exposes a single object.
  * Interface definition is done via an XML string, parsed at runtime.
  * A single method handler processes incoming D-Bus method calls, identifying the specific method by its name.
  * It leverages `GMainLoop` for asynchronous event handling.

-----