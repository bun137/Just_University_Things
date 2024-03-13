
#!/bin/bash
 awk 'BEGIN {
Mon[1]="jan" ;
Mon["1"]= "january";
Mon["01"] = "JAN";
printf("Mon[1] is printed as %s\t, Mon \n", Mon[1]);
printf("Mon[01] is printed as %s\t, Mon\n", Mon[01]);
printf("Mon[\"1\"] is printed as %s\t, Mon\n", Mon["1"]);
printf("Mon[\"01\"] this is printed as %s\t, Mon\n", Mon["01"]);
        }'

