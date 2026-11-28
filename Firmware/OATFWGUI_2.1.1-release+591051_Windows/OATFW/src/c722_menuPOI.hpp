#pragma once

#if DISPLAY_TYPE > 0
    #if SUPPORT_POINTS_OF_INTEREST == 1
struct PointOfInterest {
    const char *pDisplay;
    byte hourRA;
    byte minRA;
    byte secRA;
    int degreeDEC;
    byte minDEC;
    byte secDEC;
};

// Points of interest are sorted by DEC
// Note that you cannot add any points of interest between 0 and -1 degree Declination (don't ask).
PointOfInterest pointOfInterest[] = {
    // Name (15chars)    RA (hms)     DEC (dms)
    //0123456789012345
    
    // Default POIs (mostly northern hemisphere)
    // {">Polaris", POLARIS_RA_HOUR, POLARIS_RA_MINUTE, POLARIS_RA_SECOND, 89, 21, 6},
    // {">Altair", 19, 51, 45, 8, 55, 15},
    // {">Arcturus", 14, 16, 37, 19, 5, 21},
    // {">Big Dipper", 12, 16, 26, 56, 55, 7},
    // {">Cederblad 214", 0, 5, 46, 67, 16, 45},
    // {">Deneb (Cygnus)", 20, 42, 7, 45, 21, 12},
    // {">Elephant Trunk", 21, 39, 44, 57, 35, 31},
    // {">Heart Nebula", 2, 34, 57, 61, 31, 17},
    // {">Lagoon Nebula", 18, 5, 2, -24, 22, 52},
    // {">M31 Andromeda", 0, 43, 52, 41, 22, 53},
    // {">M33 Triangulum", 1, 35, 02, 30, 46, 5},
    // {">M42 Orion Nbula", 5, 36, 18, -5, 22, 44},
    // {">M51 Whirlpool", 13, 30, 45, 47, 5, 21},
    // {">M63 Sunflower", 13, 16, 45, 41, 55, 14},
    // {">M81 Bodes Galxy", 9, 57, 13, 68, 58, 1},
    // {">M101 Pinwheel", 14, 3, 56, 54, 15, 0},
    // {">Navi", 0, 57, 57, 60, 49, 33},
    // {">Pleiades 7Sistr", 3, 48, 15, 24, 10, 54},
    // {">Soul Nebula", 2, 52, 47, 60, 30, 56},
    // {">Vega", 18, 37, 37, 38, 48, 7},
    // {">Veil Nebula", 20, 51, 28, 30, 59, 30},

    // JNow coordinates: 2026-11-28. Precessed from J2000 using IAU 2006 model.
    // CONSTELLATIONS AND WIDE-FIELD REGIONS
    {">Southern Cross", 12, 31, 31, -60, 8, 54},
    {">Orion", 5, 36, 21, -1, 59, 3},
    {">Orion Belt", 5, 37, 35, -1, 11, 6},
    {">Scorpius", 16, 56, 43, -30, 2, 29},
    {">Southern Ptrs", 14, 21, 59, -60, 37, 20},
    {">Galactic Centre", 17, 47, 23, -29, 1, 0},
    {">Rho Ophiuchi", 16, 26, 37, -24, 3, 35},
    {">Dark Horse", 17, 21, 39, -25, 1, 32},
    {">Coalsack", 12, 54, 39, -63, 8, 44},

    // GALAXIES
    {">LMC", 5, 23, 22, -69, 43, 56},
    {">SMC", 0, 53, 40, -72, 40, 57},
    {">Sculptor Galaxy", 0, 48, 52, -25, 8, 28},
    {">Centaurus A", 13, 27, 3, -43, 9, 30},
    {">M83 Pinwheel", 13, 38, 31, -30, 0, 11},
    {">M104 Sombrero", 12, 41, 23, -11, 46, 14},
    {">M31 Andromeda", 0, 44, 13, 41, 24, 59},
    {">M33 Triangulum", 1, 35, 22, 30, 47, 51},

    // EMISSION AND REFLECTION NEBULAE
    {">Carina Nebula", 10, 44, 53, -60, 0, 30},
    {">M42 Orion", 5, 36, 36, -5, 22, 32},
    {">Horsehead Flame", 5, 42, 20, -2, 26, 47},
    {">Tarantula", 5, 38, 27, -69, 4, 49},
    {">M8 Lagoon", 18, 5, 27, -24, 22, 49},
    {">M20 Trifid", 18, 4, 14, -23, 1, 52},
    {">Lagoon+Trifid", 18, 4, 39, -23, 44, 51},
    {">M16 Eagle", 18, 20, 20, -13, 46, 14},
    {">M17 Omega", 18, 22, 21, -16, 10, 9},
    {">Rosette Nebula", 6, 35, 11, 4, 58, 33},
    {">Running Chicken", 11, 37, 52, -63, 10, 57},
    {">Cats Paw", 17, 22, 42, -36, 9, 21},
    {">Lobster Nebula", 17, 26, 31, -34, 13, 26},
    {">NGC 6188", 16, 42, 1, -48, 33, 2},
    {">Prawn Nebula", 16, 58, 52, -40, 29, 48},
    {">Statue Liberty", 11, 13, 9, -61, 28, 48},

    // GLOBULAR CLUSTERS
    {">Omega Centauri", 13, 28, 24, -47, 37, 6},
    {">47 Tucanae", 0, 25, 16, -71, 55, 53},
    {">M4", 16, 25, 15, -26, 35, 38},
    {">M22", 18, 38, 2, -23, 52, 33},
    {">NGC 6752", 19, 13, 16, -59, 56, 13},

    // OPEN STAR CLUSTERS
    {">M45 Pleiades", 3, 48, 36, 24, 11, 54},
    {">Jewel Box", 12, 55, 14, -60, 28, 44},
    {">Wishing Well", 11, 7, 33, -58, 48, 45},
    {">South Pleiades", 10, 44, 10, -64, 32, 30},
    {">M6 Butterfly", 17, 41, 51, -32, 13, 45},
    {">M7 Ptolemy", 17, 55, 42, -34, 49, 12},
    {">M44 Beehive", 8, 41, 39, 19, 53, 12},
    {">M11 Wild Duck", 18, 52, 33, -6, 13, 59},
    {">M41", 6, 48, 9, -20, 45, 51},
    {">NGC 2516", 7, 58, 45, -60, 56, 27},

    // BRIGHT STARS
    {">Sirius", 6, 46, 21, -16, 44, 45},
    {">Canopus", 6, 24, 33, -52, 42, 42},
    {">Alpha Centauri", 14, 41, 40, -60, 56, 54},
    {">Hadar", 14, 5, 45, -60, 30, 4},
    {">Achernar", 1, 38, 43, -57, 6, 2},
    {">Acrux", 12, 28, 7, -63, 14, 52},
    {">Antares", 16, 31, 3, -26, 29, 21},
    {">Betelgeuse", 5, 56, 37, 7, 24, 35},
    {">Rigel", 5, 15, 50, -8, 10, 21},
    {">Aldebaran", 4, 37, 28, 16, 33, 45},
    {">Altair", 19, 52, 5, 8, 56, 18},
    {">Arcturus", 14, 16, 56, 19, 3, 30},
    {">Spica", 13, 26, 37, -11, 18, 3},
    {">Fomalhaut", 22, 59, 7, -29, 28, 40},

    // Add new items above here, not below.
    {">Home", 0, 0, 0, 90, 0, 0},
    {">Unpark", 0, 0, 0, 90, 0, 0},
    {">Park", 0, 0, 0, 90, 0, 0},
    // And definitely don't add here.
};

int currentPOI = 0;
int parkPOI    = sizeof(pointOfInterest) / sizeof(pointOfInterest[0]) - 1;
int unparkPOI  = sizeof(pointOfInterest) / sizeof(pointOfInterest[0]) - 2;
byte homePOI   = sizeof(pointOfInterest) / sizeof(pointOfInterest[0]) - 3;

bool processPOIKeys()
{
    lcdButton_t key;
    bool waitForRelease = false;
    if (lcdButtons.keyChanged(&key))
    {
        waitForRelease = true;
        switch (key)
        {
            case btnSELECT:
                {
                    mount.stopSlewing(ALL_DIRECTIONS);
                    if (currentPOI == homePOI)
                    {
                        mount.startSlewingToHome();
                    }
                    else if (currentPOI == parkPOI)
                    {
                        mount.park();
                    }
                    else if (currentPOI == unparkPOI)
                    {
                        mount.startSlewing(TRACKING);
                    }
                    else
                    {
                        PointOfInterest *poi = &pointOfInterest[currentPOI];
                        LOG(DEBUG_INFO, "[POI]: Selected %s.  RA: %d %d %d", poi->pDisplay, poi->hourRA, poi->minRA, poi->secRA);
                        LOG(DEBUG_INFO, "[POI]: Selected %s. DEC: %d %d %d", poi->pDisplay, poi->degreeDEC, poi->minDEC, poi->secDEC);
                        long targetSeconds = (60L * abs(poi->degreeDEC) + poi->minDEC) * 60L + poi->secDEC;
                        targetSeconds *= (poi->degreeDEC < 0 ? -1 : 1);
                        mount.targetRA().set(poi->hourRA, poi->minRA, poi->secRA);
                        mount.targetDEC() = Declination::FromSeconds(targetSeconds);
                        LOG(DEBUG_INFO, "[POI]: Target RA  is %s. %ls", mount.targetRA().ToString(), targetSeconds);
                        LOG(DEBUG_INFO,
                            "[POI]: mount target DEC is %s. %ls",
                            mount.targetDEC().ToString(),
                            mount.targetDEC().getTotalSeconds());
                        mount.startSlewingToTarget();
                    }
                }
                break;

            case btnLEFT:
            case btnDOWN:
                {
                    currentPOI = adjustWrap(currentPOI, 1, 0, parkPOI);
                }
                break;

            case btnUP:
                {
                    currentPOI = adjustWrap(currentPOI, -1, 0, parkPOI);
                }
                break;

            case btnRIGHT:
                {
                    lcdMenu.setNextActive();
                }
                break;

            default:
                break;
        }
    }

    return waitForRelease;
}

void printPOISubmenu()
{
    if (mount.isSlewingIdle())
    {
        lcdMenu.printMenu(pointOfInterest[currentPOI].pDisplay);
    }
}
    #endif
#endif
