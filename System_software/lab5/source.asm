START 100
L1  MOVER AREG,=5
    MOVEM BREG X
    SUB   AREG,=2
    LTORG
    MOVER AREG Y
    BC any,L1
    ADD CREG,4
X   DC  5
Y   DS  2
    END
