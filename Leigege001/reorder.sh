c=12
for ((i=6;i>=4;i--))
do
       	for j in `ls chapter$c/`
       	do
       		s1=${j%%_*}
       		if [ $s1 = $i ]; then
       			file=$j
       			ss=`expr $i + 1`
       			file=${file//$s1/$ss}
       			echo "git mv chapter$c/$j chapter$c/$file"
       			git mv chapter$c/$j chapter$c/$file
       		fi
       	done
done
exit 0
