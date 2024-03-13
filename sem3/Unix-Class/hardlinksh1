
function reversingString() {
  local frtArgu="$1"
  local reverseFrtArgu=$(rev <<< "$frtArgu")
  echo "$reverseFrtArgu"
  
}

function renamingFiles() {
  local dir="$1"
  local ext="$2"
find "$dir" -type f -name "$ext" | while read -r file;
do
    if [ -f "$file" ]; then
      filename=$(basename "$file")
      filebase="${filename%$ext}"
      newname="${dir}/${filebase}.png"
      mv "$file" "$newname"
      echo "Renaming file from: $file to $newname"
    fi
  done
}

function findDisplay() {
  local dir="$1"
  local pattern="$2"
  if [ ! -d "$dir" ]; then
    echo "Directory does not exist. Exiting the application!"
    exit 253
  fi
  local result=($(find "$dir" -type f -name "$pattern"))
  local matches=${#result[@]}
  echo "The number of files matched: $matches"
  [ $matches -gt 0 ] && printf "%s\n" "${result[@]}"
}

read -p "Enter SRN: " SRN
read -p "Enter Password: " PWD
read -p "Enter Directory: " DIR

mySRN="PES2UG22CS209"
PATTERN="*.pnG"
reverse_PWD=$(reversingString "$PWD")

if [ "$SRN" = "$mySRN" ] && [ "$reverse_PWD" = "$SRN" ]; then
  echo "Username and Password are correct!"
  findDisplay "$DIR" "$PATTERN"
  renamingFiles "$DIR" "$PATTERN"
else
  if [ "$SRN" != "$mySRN" ]; then
    echo "Invalid Username. Exiting the application."
  else
    echo "Invalid Password. Exiting the application."
  fi
  exit 255
fi