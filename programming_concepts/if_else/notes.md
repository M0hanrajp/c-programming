### Learnings

- Here edgex_device_parseClients is a function that is declared as void type (does not return anything).
- deviceservices_config is pointer that is NULL or not NULL.
- if it's NULL then if condition is evaluated to !(NULL) i.e. true
- if it's NOT NULL then edgex_device_parseClients is evaluated since this is of type void it creates a problem.
    - Ternery operator is used `if(deviceservices_config ? edgex_device_parseClients(...) : NULL)`
    - ternary operator must return a value, because its result is used in the if.
```c
    if(!(deviceservices_config ? 
        edgex_device_parseClients (svc->logger, 
        iot_data_string_map_get (deviceservices_config, "Clients"), 
        &svc->config.endpoints) : NULL))
```

### Using a pointer in if statement
- take a pointer variable, int *ptr,
```c
if(ptr)
```
- if ptr is assigned to NULL, if condition fails.
- if ptr is uninitialized then behavior is undefined (not sure if condition will be true / false).
C spec: 23(draft) 6.7.9
![Image](https://github.com/user-attachments/assets/0dd29f56-8359-40da-90da-11ffd5afe5fe)
