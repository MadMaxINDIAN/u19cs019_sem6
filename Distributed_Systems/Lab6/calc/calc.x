/* This is the IDL file -- name it as calc.x*/
/*combine the arguments to be passed to the server side in a structure*/
struct numbers
{
    int a;
    int b;
    char sym;
};
program calc_PROG
{
    version calc_VERS
    {
        int calc(numbers) = 1;
    }
    = 1;
}= 0x4562877;