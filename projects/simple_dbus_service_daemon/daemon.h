#ifndef DAEMON_H
#define DAEMON_H

#include <gio/gio.h>

extern void onNameAcquiredHandler(GDBusConnection* connection,
                                  const gchar* name,
                                  gpointer user_data);

extern void onBusAcquiredHandler(GDBusConnection* connection,
                                 const gchar* name,
                                 gpointer user_data);

extern void onNameLostHandler(GDBusConnection* connection,
                              const gchar* name,
                              gpointer user_data);

#endif
