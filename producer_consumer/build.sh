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

# Build producer and consumer
gcc $SCRIPT_DIR/producer.c -o $SCRIPT_DIR/producer &
gcc $SCRIPT_DIR/consumer.c -o $SCRIPT_DIR/consumer

echo "producer: $SCRIPT_DIR/producer"
echo "consumer: $SCRIPT_DIR/consumer"
