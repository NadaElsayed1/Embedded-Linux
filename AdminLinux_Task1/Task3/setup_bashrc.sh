#!/bin/bash

# Check if .bashrc exists in my home directory
if [ -f "$HOME/.bashrc" ]; then
  # Append environment variables to .bashrc
  echo "export HELLO=\$HOSTNAME" >> "$HOME/.bashrc"
  echo "LOCAL=\$(whoami)" >> "$HOME/.bashrc"
  echo "echo \$LOCAL" >> "$HOME/.bashrc"  # This is to print my username when new terminal open
fi

#Then open another terminal
gnome-terminal &