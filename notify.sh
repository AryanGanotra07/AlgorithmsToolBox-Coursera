echo "*** Welcome ****"
echo "*** Your live coding script is running ***" 
echo
read -p "Enter your file extention : " ext
echo "Looking for changes in $ext files"
fswatch $PWD -e ".*" -i "\\.$ext$" |  xargs -0 -I {} 