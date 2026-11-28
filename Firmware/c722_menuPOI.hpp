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
    {">Southern Cross", 12, 31, 31, -60, 8, 54},  // Crux
    {">Orion", 5, 36, 21, -1, 59, 3},             // Orion constellation
    {">Rho Ophiuchi", 16, 26, 37, -24, 3, 35},    // Rho Ophiuchi cloud complex
    {">Galactic Centre", 17, 47, 23, -29, 1, 0},  // Milky Way Galactic Centre
    {">Coalsack", 12, 54, 39, -63, 8, 44},        // Coalsack dark nebula

    // GALAXIES
    {">LMC", 5, 23, 22, -69, 43, 56},             // Large Magellanic Cloud
    {">SMC", 0, 53, 40, -72, 40, 57},             // Small Magellanic Cloud (NGC 292)
    {">Sculptor Galaxy", 0, 48, 52, -25, 8, 28},  // NGC 253, Silver Coin Galaxy
    {">Centaurus A", 13, 27, 3, -43, 9, 30},      // NGC 5128, Caldwell 77
    {">String Pearls", 0, 16, 14, -39, 2, 50},    // NGC 55, String of Pearls Galaxy
    {">NGC 300", 0, 56, 10, -37, 32, 20},         // NGC 300, Sculptor

    // EMISSION AND REFLECTION NEBULAE
    {">Carina Nebula", 10, 44, 53, -60, 0, 30},   // NGC 3372, Eta Carinae Nebula
    {">Orion Nebula", 5, 36, 36, -5, 22, 32},     // M42, NGC 1976
    {">Lagoon+Trifid", 18, 4, 39, -23, 44, 51},   // M8 (NGC 6523) + M20 (NGC 6514)
    {">Tarantula", 5, 38, 27, -69, 4, 49},        // 30 Doradus, NGC 2070
    {">Running Chicken", 11, 37, 52, -63, 10, 57},// IC 2944, Lambda Centauri Nebula
    {">Statue Liberty", 11, 13, 2, -61, 27, 14},  // NGC 3576, Statue of Liberty Nebula

    // GLOBULAR CLUSTERS
    {">Omega Centauri", 13, 28, 24, -47, 37, 6},  // NGC 5139, Caldwell 80
    {">47 Tucanae", 0, 25, 16, -71, 55, 53},      // NGC 104, Caldwell 106
    {">NGC 1851", 5, 15, 0, -40, 1, 1},          // NGC 1851, Caldwell 73
    {">NGC 362", 1, 4, 9, -70, 42, 17},          // NGC 362, Caldwell 104

    // OPEN STAR CLUSTERS
    {">Pleiades", 3, 48, 36, 24, 11, 54},         // M45, Melotte 22
    {">Jewel Box", 12, 55, 14, -60, 28, 44},      // NGC 4755, Caldwell 94
    {">Wishing Well", 11, 7, 33, -58, 48, 45},    // NGC 3532, Caldwell 91
    {">South Pleiades", 10, 44, 10, -64, 32, 30}, // IC 2602, Caldwell 102
    {">Butterfly Clust", 17, 41, 51, -32, 13, 45},// M6, NGC 6405
    {">Ptolemy Cluster", 17, 55, 42, -34, 49, 12},// M7, NGC 6475
    {">South Beehive", 7, 58, 45, -60, 56, 27},   // NGC 2516, Caldwell 96
    {">Omicron Velorum", 8, 41, 22, -53, 7, 48},  // IC 2391, Caldwell 85
    {">False Comet", 16, 56, 4, -41, 51, 14},     // NGC 6231, Caldwell 76
    {">Pearl Cluster", 11, 37, 31, -61, 45, 54},  // NGC 3766, Caldwell 97
    {">NGC 2477", 7, 53, 8, -38, 36, 28},         // NGC 2477, Caldwell 71

    // BRIGHT STARS
    {">Sirius", 6, 46, 21, -16, 44, 45},          // Alpha Canis Majoris
    {">Canopus", 6, 24, 33, -52, 42, 42},        // Alpha Carinae

    // RESERVED SYSTEM ENTRIES
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
