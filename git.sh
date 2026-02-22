#!/bin/bash                                             #this is called shebang line in bash

echo "Enter file to add in staging area: "
read file

echo "Enter commiting message: "
read message

echo "Enter branch: "
read branch

if [ "$file" = "." ]; then
git add $file

else
git add "./$file"
fi

git status

echo "y or no for confirmation:  "
read confirm

if [ "$confirm" = "y" ] || [ "confirm" = "Y" ]; then
git commit -m "$message"
git push origin "$branch"

else
echo "process cancel but files still in stagging area"

fi


