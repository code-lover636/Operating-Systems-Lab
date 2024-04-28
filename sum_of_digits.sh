echo "Enter a number"
read num

sum=0

while [ $num -gt 0 ]
do
  sum=$((num % 10 + sum)) 
  num=$((num / 10))    
done

echo "Sum=$sum"
