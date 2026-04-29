#!/bin/bash

REAL_USER=${SUDO_USER:-$USER}
REAL_HOME=$(getent passwd "$REAL_USER" | cut -d: -f6)

BIN_DIR="$REAL_HOME/.local/bin"
ICON_DIR="$REAL_HOME/.local/share/icons"
APP_DIR="$REAL_HOME/.local/share/applications"
DATA_DIR="$REAL_HOME/.local/share/AppRun.wrapped"

# Use -f to avoid "file not found" errors
rm -f "$ICON_DIR/euclideus_icon.png"
rm -f "$BIN_DIR/Euclideus-x86_64.AppImage"
rm -f "$APP_DIR/Euclideus.desktop"
rm -f "$DATA_DIR/euclideus_auto_save.core"

# Optional: Remove the data directory if it's now empty
[ -d "$DATA_DIR" ] && rmdir "$DATA_DIR" 2>/dev/null

# Force COSMIC to refresh the launcher list
update-desktop-database "$APP_DIR"

echo "Uninstall complete."
