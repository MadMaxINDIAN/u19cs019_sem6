struct strpair{
    char a[50];
    char b[50];
};

program ARR_PROG{
    version VERSION1 {
        int substring(strpair p) = 1;
    } = 1;
} =  0x4562877;