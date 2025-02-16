SKIP_GCC_CHECK=$1
# Check if gcc exists by checking its version
if [ "$SKIP_GCC_CHECK" != "-skip-check" ] && [ "$SKIP_GCC_CHECK" != "-s" ]; then
    if gcc --version >/dev/null 2>&1; then
        echo "using gcc version: \n"
        gcc --version
        echo "\n"
    else
        echo "gcc not installed"
        exit 1
    fi
fi

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Build main program
gcc "$SCRIPT_DIR/cli_argument_processing.c" -o "$SCRIPT_DIR/cli_argument_processing"

echo "executable: $SCRIPT_DIR/cli_argument_processing"
