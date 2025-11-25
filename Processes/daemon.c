#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <fcntl.h>
#include <string.h>

void daemonize() {
    pid_t pid, sid;
    
    // TODO 1: Fork the parent process
    // The parent process exits immediately, leaving the child running in background.
   
    // TODO 2: Change the file mode mask (umask)
    // This allows the daemon to control the permissions of files it creates.

    // TODO 3: Create a new Session ID (SID) for the child process
    // This detaches the process from its controlling terminal.
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    // TODO 4: Change the current working directory to the root directory
    // This prevents the daemon from blocking a mount point from being unmounted.
    
    // TODO 5: Close standard file descriptors (stdin (STDIN_FILENO), 
	// stdout (STDOUT_FILENO, stderr (STDERR_FILENO) 
    // Daemons should not use the terminal.
    
   
    openlog("simple_daemon", LOG_PID|LOG_CONS, LOG_DAEMON);
    syslog(LOG_INFO, "Daemon successfully started.");
}

int main() {
    
    daemonize();

    // --- Daemon's main execution loop ---
    while (1) {
        // This is where the actual service logic goes
        syslog(LOG_INFO, "Daemon heartbeat: Service running...");
        sleep(10); // Sleep for 10 seconds
    }

    // This part is unreachable in this simple example, but for proper daemons:
    syslog(LOG_INFO, "Daemon terminated.");
    closelog();
    
    exit(EXIT_SUCCESS);
}
