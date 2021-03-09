# Networking

## Drivers

Depending on the machine, you might need to manually download a package containing the drivers for your card. In some cases you might need to get a third-party card.

## WiFi

To scan networks and connect easily with them, using the `nmcli` tool is really helpful. To get started you need to install the following: 

`sudo apt-get install network-manager`

### Bash Snippets

To scan for nearby networks do

```bash
nmcli dev wifi
```

To connect to a network do

```bash
nmcli dev wifi connect <SSID> password <THE-PASSWORD> 

```

To see the status of your network devices

```bash
nmcli dev -p device

```

To take down a device

```bash
sudo ip link set <DEVICE-NAME> down
```