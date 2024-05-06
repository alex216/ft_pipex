# allowed_funcs
allowed_funcs=("read" "write" "malloc" "free" "exit" "error" "access" \
	"unlink" "wait" "strerror" "pipe" "open" "fork" "dup" "execve" "dup2" "close")

# exclude path
dont_peektest="./test/*"
dont_peeklibft="./libft/*"
dont_peeklibfttest="./libft/test"

# to check if a function is forbidden
function is_allowed() {
    local func="$1"
    if [[ "${allowed_funcs[@]}" =~ "${func}" ]]; then
        return 0
    fi
    return 1
}

check_product_symbols() {
	res=0
    local product="$1"
    local undefined_symbols=$(nm -u "$product" | sed 's/^_*//')
    for symbol in $undefined_symbols; do
		if is_allowed "$symbol"; then
			:
		else
            echo "Error: $product: forbidden function used: ${symbol}"
			res=1
        fi
    done
	if [ $res -eq 0 ]; then
		echo "No forbidden functions found."
		echo $res
	fi
	exit $res
}

debug() {
	# search mischief functions
	find . -type f -name "*.o" -not \( -path "$dont_peektest" -o -path "$dont_peeklibft" \) | \
	while read -r obj_file; do
		echo "## Checking symbols in $obj_file"
		nm -u "$obj_file" | sed 's/^_*//' | \
		while read -r symbol; do
    		if [[ "${symbol}" =~ ^[x|ft].* ]]; then
				:
			elif is_allowed "$symbol"; then
				:
			else
				echo ${symbol}
			fi
		done
	done
}

##########################################
if [ "$1" = "-d" ]; then
    debug
else
    check_product_symbols pipex
fi
