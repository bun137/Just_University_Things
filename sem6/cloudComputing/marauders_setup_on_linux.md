# Marauders Setup and Usage on Linux

1. Install `socat` to expose the port. `socat` is a networking tool for relaying data between sockets.
   - If you use Arch or an Arch based distro, install via `yay` or `paru`.
   - If you use Debian based distros, you can simply do `apt install socat`.
2. On a new terminal run `sudo socat TCP-LISTEN:2375,reuseaddr,fork UNIX-CONNECT:/var/run/docker.sock`. Make sure this is running on another terminal when you are running the python file.
   - `TCP-LISTEN:2375`: Listens for incoming TCP connections on the port 2375.
   - `reuseaddr`: Allows the port to be quickly reused if the process happens to restart.
   - `fork`: Allows multiple connections.
   - `UNIX-CONNECT: /var/run/docker.sock`: This lets us connect to the DOCKER UNIX socket, where the Docker daemon listen for API requests.
   - This essentially allows remote clients to interact with Docker over TCP instead of using the default UNIX Socket. In simple words, makes the Docker API accessible via HTTP over TCP.

> [!Note]
> If you have a firewalls like `iptables` or `ufw` enabled, you might need to disable the service or configure them to allow traffic on port 2375.

Once you are done with running `marauders.py`, you can terminate the `socat` process and exit the terminal.
