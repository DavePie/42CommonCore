cut -d ':' -f 1 /etc/passwd | sed '/^#/d' | awk 'NR % 2 == 0' | rev  | sort -r | head -n "$FT_LINE2" | tail -n +"$FT_LINE1" | tr '\n' ',' | sed 's/,/, /g' | sed 's/..$/./' | tr -d '\n'
