#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main()
{
  char buffer[BUFFER_SIZE];
  char source[256];
  char destination[256];
  int source_file;
  int destination_file;
  int read_bytes;

  printf("Enter the source file name: ");
  scanf("%s", source);

  printf("Enter the target file name: ");
  scanf("%s", destination);

  source_file = open(source, O_RDONLY);

  if (source_file == -1)
  {
    printf("The source file does not exist!\n");
    return 1;
  }

  destination_file = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);

  if (destination_file == -1)
  {
    perror("Error opening/creating the target file!\n");
    close(source_file);
    return 1;
  }

  while ((read_bytes = read(source_file, buffer, BUFFER_SIZE)) > 0)
  {
    if (write(destination_file, buffer, read_bytes) != read_bytes)
    {
      perror("Error writing to the target file!\n");
      close(source_file);
      close(destination_file);
      return 1;
    }
  }

  if (read_bytes == -1)
  {
    perror("Error reading the source file!\n");
    return 1;
  }

  close(source_file);
  close(destination_file);

  printf("File copy successful!\n");
  return 0;
}