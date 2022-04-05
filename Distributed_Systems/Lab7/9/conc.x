struct strpair{
    char a[50];
    char b[50];
};
struct str{
    char ans[100];
};

program ARR_PROG{
    version VERSION1 {
        str conc(strpair p) = 1;
    } = 1;
} =  0x4562877;