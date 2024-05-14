# Program to print the sum of digits of a number

read -p "Enter a number: " num

sum=0

while [ $num -gt 0 ]
do
  sum=$((num % 10 + sum)) 
  num=$((num / 10))    
done

echo Sum of digits is $sum.
