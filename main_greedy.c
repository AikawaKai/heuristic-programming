#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "greedy.h"


void parse_command_line (int argc, char *argv[], char *data_file, int *pparam);


int main (int argc, char *argv[])
{
  char data_file[NAME_LENGTH];
  data_t I;
  solution_t x;
  int param;
  time_t inizio, fine;
  double tempo;


  parse_command_line(argc,argv,data_file,&param);

  load_data(data_file,&I);
  //print_data(&I);
  create_solution(I.n,&x);
  inizio = clock();
  greedy(&I,&x);
  fine = clock();
  tempo = (double) (fine - inizio) / CLOCKS_PER_SEC;

  printf("%s ",data_file);
  printf("%10.6lf ",tempo);
  print_solution(&x);
  printf("\n");

  destroy_solution(&x);
  destroy_data(&I);

  return EXIT_SUCCESS;
}


void print_usage (char *command)
{
  fprintf(stderr,"Use: %s [datafile] [param]\n",command);
  fprintf(stderr,"datafile: name and path of data file\n");
  fprintf(stderr,"param:    integer parameter (optional!)\n");
}


void parse_command_line (int argc, char *argv[], char *data_file, int *pparam)
{
  if ( (argc != 2) && (argc != 3) )
  {
    print_usage(argv[0]);
    exit(EXIT_FAILURE);
  }

  strcpy(data_file,argv[1]);
  if (argc == 3)
  {
    if (sscanf(argv[2],"%d",pparam) == 0)
    {
      print_usage(argv[0]);
      exit(EXIT_FAILURE);
    }
  }
}
