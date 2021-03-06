#include <unistd.h>
#include <stdio.h>
#include <plugin.h>
#include <mysql_version.h>

//plugin descriptor

struct st_mysql_daemon my_daemon_plugin = 
{
	MYSQL_DAEMON_INTERFACE_VERSION
};

// plugin declaration

static int plugin_hoterran_init(void* p)
{
	fprintf(stderr, "plugin_hoterran_init\n");
	return 0;
}

static int plugin_hoterran_deinit(void* p)
{
	fprintf(stderr, "plugin_hoterran_deinit\n");
	return 0;
}

mysql_declare_plugin(hoterran)
{	
	MYSQL_DAEMON_PLUGIN,
	&my_daemon_plugin,	
	"hoterran",
	"hoterran",
	"test",
	PLUGIN_LICENSE_BSD,
	plugin_hoterran_init,
	plugin_hoterran_deinit,
	0x0001,
	NULL,
	NULL,
	NULL
}
mysql_declare_plugin_end;
