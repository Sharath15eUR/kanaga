#!/bin/bash
#

#Using Special Parameters to check the number of command line arguements passed
if [ $# -eq 0 ];then
    echo "Invalid format!!"
    echo "Try using --help option for more details"
    exit 1
fi


search(){
    option=$1
    directory=$2
    keyword=$3
    if [ "$option" = "-d" ];then
        for file in "$directory"/*; do
            if [ -d "$file" ]; then
                #Recursive function call to iterate through all the files and subdirectories in the directory
                search "$option" "$file" "$keyword" 
            elif [ -f "$file" ]; then
                grep -q "$keyword" "$file" 
                if [ $? -eq 0 ]; then
                    echo "$keyword found in $file"
                    #File Handling and Error Redirection. Redirecting errors related to file
                    grep -nH "$keyword" "$file">>"output.txt" 2>> errors.log
                fi
            fi
        done
    else
        grep -nH "$keyword" "$directory" > output.txt 2>> errors.log && echo "$keyword found in $directory" 
    fi
}

#Using Here Document to display the help option
help(){
        cat << --HELP
        NAME:
                file_analyzer.sh
        SYNOPSIS:
                ./file_analyzer.sh [OPTION ...] FILE NAME [OPTION ...] PATTERN
        DESCRIPTION:
                This Shell Script recursively searches for an keyword either in a directory or a file according to the option chosen
        OPTIONS:
                -d,directory search
                         Recursively searches all the contents of the directory and its subdirectories for the given keyword
                -k,keyword
                        Keyword to search
                -f,file search
                        File to search directly
                --help
                        Display the help menu.

--HELP
}

if [ "$1" = "-d" ] ||[ "$1" = "-f" ];then
        if [ $# -eq 4 ] && [ "$3" = "-k" ];then
                option=$1
                #Using Regular Expression to validate the input keyword
                if ! echo "$4" | grep -qE '^[a-zA-Z0-9]+$'; then
                        echo "Invalid keyword: '$4'. Only non-empty alphanumeric characters are allowed." >> errors.log
                        exit 1
                else
                        word_to_search=$4
                fi
                directory_to_search=$2
                search $option $directory_to_search $word_to_search
        else
                echo "Invalid format!!"
                echo "Try using --help option for more details"
                exit 1
        fi
elif [ "$1" = "--help" ];then
        help
else
        echo "Invalid format!!"
        echo "Try using --help option for more details"
        exit 1
fi
