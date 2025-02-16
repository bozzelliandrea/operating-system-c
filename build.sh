# sh script to build every executable of the assessment
echo "*** C Exercises ***"
echo "\n"
echo "Problem 1: Array Manipulation and Functions"
sh ./array_manipulation/build.sh -s

echo "Problem 2: String Operations"
sh ./string_operations/build.sh -s

echo "Problem 3: Command Line Argument Processing"
sh ./command_line_argument/build.sh -s

echo "Problem 4: Basic File Reading"
sh ./basic_file_reading/build.sh -s

echo "\n"
echo "*** OS Programming Question ***"
echo "\n"

echo "Problem 1: Simple Scheduling Algorithm"
sh ./simple_scheduling_algorithm/build.sh -s

echo "Problem 2: Creating Processes"
sh ./creating_processes/build.sh -s

echo "Problem 3: Interprocess Communications (producer/consumer)"
sh ./producer_consumer/build.sh -s

echo "Problem 4: Multithreading"
sh ./multithreading/build.sh -s
