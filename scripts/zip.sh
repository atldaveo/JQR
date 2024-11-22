find . -type d -name "practical_exercises" | while read dir; do
    (cd "$dir" && zip -r "../${dir##*/}.zip" .)
done
