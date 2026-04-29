#!/bin/bash

# ... [Keep your existing variables and setup] ...
REAL_USER=${SUDO_USER:-$USER}
REAL_HOME=$(getent passwd "$REAL_USER" | cut -d: -f6)
BIN_DIR="$REAL_HOME/.local/bin"
ICON_DIR="$REAL_HOME/.local/share/icons"
APP_DIR="$REAL_HOME/.local/share/applications"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# ... [Keep your directory creation and extraction] ...
mkdir -p "$BIN_DIR" "$ICON_DIR" "$APP_DIR"
chmod +x "$SCRIPT_DIR/Euclideus-x86_64.AppImage"
./Euclideus-x86_64.AppImage --appimage-extract

# Define file names
APP_NAME="Euclideus-x86_64.AppImage"
ICON_NAME="euclideus_icon.png"
DESKTOP_FILE="Euclideus.desktop"

# Copy files
cp "$SCRIPT_DIR/$APP_NAME" "$BIN_DIR/"
cp "$SCRIPT_DIR/squashfs-root/usr/share/desktop-deployment/$ICON_NAME" "$ICON_DIR/"
cp "$SCRIPT_DIR/squashfs-root/usr/share/desktop-deployment/$DESKTOP_FILE" "$APP_DIR/"

# FIX: Update paths inside the .desktop file for COSMIC
sed -i "s|^Exec=.*|Exec=$BIN_DIR/$APP_NAME|" "$APP_DIR/$DESKTOP_FILE"
sed -i "s|^Icon=.*|Icon=$ICON_DIR/$ICON_NAME|" "$APP_DIR/$DESKTOP_FILE"

# Refresh the desktop database so COSMIC sees the change immediately
update-desktop-database "$APP_DIR"

# ... [Keep your chown and cleanup] ...
chown -R "$REAL_USER:$REAL_USER" "$BIN_DIR/$APP_NAME" "$ICON_DIR/$ICON_NAME" "$APP_DIR/$DESKTOP_FILE"
rm -r "$SCRIPT_DIR/squashfs-root"
