#!/usr/bin/bash

# Clone repo
# echo "Downloading repo..."
# exec git clone https://github.com/KaziRifatMorshed/Quote-of-my-day.git &
# exec cd Quote-of-my-day &

# install or download library and dependencies
# if; then # incomplete
#     exec sudo pacman -S glfw &
#     exec git clone https://github.com/cococry/leif.git && cd leif/ && ./install.sh &
#     exec paru -S libclipboard-git &
# fi

# Compile
# if which clang >/dev/null 2>&1; then
#     echo "Clang is installed, using clang"
#     exec clang Quote_of_my_day.c -o Quote_of_my_day -lglfw -lGL -lleif -lclipboard -lm &
# else
#     echo "Clang is not installed, using GCC instead"
#     exec gcc Quote_of_my_day.c -o Quote_of_my_day -lglfw -lGL -lleif -lclipboard -lm &
# fi

# copy .desktop and executable file
exec cp Quote_of_my_day.desktop ~/.local/share/applications &
exec cp Quote_of_my_day ~/Applications/ &

# append
echo "exec ~/Applications/Quote_of_my_day &" >>~/.config/openbox/autostart &

echo "The End"
