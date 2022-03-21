/* This is the IDL file -- name it as add.x*/
/*combine the arguments to be passed to the server side in a structure*/
struct numbers
{
    int a;
};
program PRIME_PROG
{
    version PRIME_VERS
    {
        int prime(numbers) = 1;
    }
    = 1;
}= 0x4562877;