struct arr{
    int size;
    int a[50];
};

program REV_PROG{
    version REV_VERS {
        arr rev(arr p) = 1;
    } = 1;
} =  0x4562877;