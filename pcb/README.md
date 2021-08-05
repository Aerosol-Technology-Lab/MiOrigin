# MiOrigin Controller PCB
PCB Schematic and Layour for MiOrigin Controller designed on KiCad

## Revisions
### Rev 1.1 
#### Updates since past revision (Rev 1.0)
1. Moved protection USB diodes to the front of the board
1. Replaced wrong footprint with correct size for the Tri-State Buffer (see Rev 1.0-Known Issue #2)

#### Known Issues
1. RS-232 TX and RX line are switched between the MAX-3232 IC and the D-Sub port. Continuing issue from previous revision (see Rev 1.0-Known Issue #1)

### Rev 1.0
#### Known Issues
1. RS-232 TX and RX line are switched between the MAX-3232 IC and the D-Sub port
1. Footprint for Tri-State Buffer is smaller than actual IC. Careful soldering is required
