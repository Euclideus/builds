#!/bin/bash

REAL_USER=${SUDO_USER:-$USER}
REAL_HOME=$(getent passwd "$REAL_USER" | cut -d: -f6)

BIN_DIR="$REAL_HOME/.local/bin"
ICON_DIR="$REAL_HOME/.local/share/icons"
APP_DIR="$REAL_HOME/.local/share/applications"
DATA_DIR="$REAL_HOME/.local/share/AppRun.wrapped"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

rm "$ICON_DIR/euclideus_icon.png"
rm "$BIN_DIR/Euclideus-x86_64.AppImage"
rm "$APP_DIR/Euclideus.desktop"
rm "$DATA_DIR/euclideus_auto_save.core"
