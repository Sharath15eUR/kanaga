#!/bin/bash
#
#Handle Command Line Arguments 

if [ $# -eq 3 ];then
	source_directory=$1
	destination_directory=$2
	file_type=$3
else
	echo "Positional Arguements passed does not correspond to the required format, Please Try Again!"
fi

#echo "$source_directory $destination_directory $file_type"

#Declare Array to Hold all the file names of the files in the source folder that are of the given file type
declare -a backup_files

#Globbing
echo "Files that match the given extention are:"
ls $source_directory/*$file_type

#Export Statement to set a global variable to hold the count of number of backed up files
export BACKUP_COUNT=0
total_size_backedup=0

#Array Operation 
backup_files=($source_directory/*$file_type)
echo "Files to be backed up:"
for file in "${backup_files[@]}";
do
	file_size=$(stat --format="%s" "$file")
    	echo "$file ($file_size bytes)"
done

#Conditional Execution
#Checking for presence of files of required file type in source directory
if [ ${#backup_files[@]} -eq 0 ];then
	echo "No files are present in $source_directory of $file_type extention"
	exit 1
fi

#Checking for Existence of Backup Directory
if [ ! -d $destination_directory ];then
	#Creating Backup Directory if already non-existent 
	mkdir -p $destination_directory
	if [ $? -ne 0 ];then
		echo "Failed to create directory : $destination_directory"
		exit 1
	fi
fi

#Backup
for file in "${backup_files[@]}";
do
	#To remove the Directory name associated in the file and extract only file name
	file_name=$(echo "$file" | awk -F "/" '{print $NF}')
	#Backup File
	current_backup_file="$destination_directory/$file_name"
	#Getting the size of the file
	file_size=$(stat --format="%s" "$file")
	#Checks if the current file to backup is already present in the backup destination
	if [ -f "$current_backup_file" ];then
		#Compare the timestamps of file in the directory with backup file
		if [ "$file" -nt "$current_backup_file" ];then
			old_file_size=$(stat --format="%s" "$current_backup_file")
			total_size_backedup=$((total_size_backedup-old_file_size))
			#Overwrite the old file with newer contents
			cp "$file" "$current_backup_file"
			#Calculating total size of files backed up
			total_size_backedup=$((total_size_backedup+file_size))
		fi
	else

		#If file is not already present in the backup folder, backup the file
		cp "$file" "$current_backup_file"
		#Calculatinf total size of the files backed up
		total_size_backedup=$((total_size_backedup+file_size))
	fi
	BACKUP_COUNT=$(($BACKUP_COUNT+1))
done

#Output Report
#Create Backup Report Log file if non existent
backup_report_log="$destination_directory/backup_report.log"
if [ ! -f "$backup_report_log" ];then
	touch "$backup_report_log"
fi
{
echo ""
echo "Back Up Report : "
echo "Date of Backup : `date`"
echo "*************************************"
echo "Total number of files processed : $BACKUP_COUNT"
echo "Total size of files processed : $total_size_backedup"
} >> "$backup_report_log"

if [ $? -eq 0 ];then
	echo "Automation Script Successfully Completed and Report Log successfully saved"
	exit 0
else
	echo "Failed to save Report Log"
	exit 1
fi
