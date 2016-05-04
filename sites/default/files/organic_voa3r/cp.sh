
#!/bin/bash
for file in $(ls -p)
do
#cp $file /other/location
iconv -f us-ascii -t UTF-8 $file > /var/www/html/organic/sites/default/files/UTF8_organic_voa3r/$file
#echo $file
done
