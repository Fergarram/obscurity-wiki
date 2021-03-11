TODO: Add commands for setting the natural scrolling and i3 settings, etc.

```bash
xinput --list
```

```bash
xinput --list-props "The name of the device"
```

```bash
xinput set-prop "The name of the device" <PROP_NO> 1
```

```bash
xrandr --output LVDS-1 --brightness 0.5
```

Using blugon

```bash
sudo apt install libxrandr2 libxrandr-dev libx11-dev
git clone https://github.com/jumper149/blugon.git

cd blugon/
make
sudo make install

mkdir -p ~/.config/blugon/
cp /usr/share/blugon/configs/default/gamma ~/.config/blugon/gamma
blugon --printconfig > ~/.config/blugon/config

(blugon&)
killall blugon

```

Setting default text editor

```bash
update-alternatives --install /usr/bin/editor editor /usr/bin/subl 10
sudo update-alternatives --config editor
```