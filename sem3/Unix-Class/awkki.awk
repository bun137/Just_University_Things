BEGIN {
  FS=":"
  printf( "Marine Part\nMain catalog\n")
            printf ("%10s %10s %10s",Part-id, name , price )
            print("==============================")
          }
          {  print  $1 $2 $3}

END{
  printf("catalog has %d parts", NR)
  }
