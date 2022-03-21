/* This is the IDL file -- name it as add.x*/
/*combine the arguments to be passed to the server side in a structure*/
struct numbers
{
    int size;
    int a[20];
};
program MAXINT_PROG
{
    version MAXINT_VERS
    {
        int MAXINT(numbers) = 1;
    }
    = 1;
}= 0x4562877;