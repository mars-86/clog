#include "../src/clog.h"

int main(void)
{
	clog_printc(CLOG_CRIT, "Critical failure %d", 1);
	clog_printc(CLOG_CRIT, "Critical failure %d", 2);

	clog_printc(CLOG_ERRO, "Error %d", 1);
	clog_printc(CLOG_ERRO, "Error %d", 2);

	clog_printc(CLOG_WARN, "Warning %d", 1);
	clog_printc(CLOG_WARN, "Warning %d", 2);

	clog_printc(CLOG_INFO, "Starting up %d", 1);
	clog_printc(CLOG_INFO, "Module started");

	clog_printc(CLOG_DEBU, "Starting up %d", 1);
	clog_printc(CLOG_DEBU, "Module started");

	clog_printc(CLOG_TRAC, "Starting up %d", 1);
	clog_printc(CLOG_TRAC, "Module started");

	return 0;
}
