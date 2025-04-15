if [ $# -ne 1 ]; then
    echo "Usage: $0 <file-or-directory>"
    exit 1
fi

TARGET=$1

if [ ! -e "$TARGET" ]; then
    echo "Error: '$TARGET' not found."
    exit 1
fi


stat --format="Name: %n | Size: %s bytes | Owner: %U | Group: %G | Permissions: %A" "$TARGET"


if [ -d "$TARGET" ]; then
    echo "Contents of directory '$TARGET':"
    ls -lh "$TARGET"
fi

