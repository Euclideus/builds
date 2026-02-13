#!/bin/bash

REAL_USER=${SUDO_USER:-$USER}
REAL_HOME=$(getent passwd "$REAL_USER" | cut -d: -f6)

BIN_DIR="$REAL_HOME/.local/bin"
ICON_DIR="$REAL_HOME/.local/share/icons"
APP_DIR="$REAL_HOME/.local/share/applications"

mkdir -p "$BIN_DIR" "$ICON_DIR" "$APP_DIR"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cp "$SCRIPT_DIR/Euclideus-x86_64.AppImage" "$BIN_DIR/"
cp "$SCRIPT_DIR/euclideus_icon.png" "$ICON_DIR/"
cp "$SCRIPT_DIR/Euclideus.desktop" "$APP_DIR/"

chown -R "$REAL_USER:$REAL_USER" "$BIN_DIR/Euclideus-x86_64.AppImage"
chown -R "$REAL_USER:$REAL_USER" "$ICON_DIR/euclideus_icon.png"
chown -R "$REAL_USER:$REAL_USER" "$APP_DIR/Euclideus.desktop"

chmod +x "$BIN_DIR/Euclideus-x86_64.AppImage"