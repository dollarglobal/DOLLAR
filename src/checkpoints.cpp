// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2014 DollarCoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //

    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
        ( 0, uint256("0xe3b969e144bd1f50aa58a3a043d5e89c1c0fb224e5abb82aa5745921d1e5774b"))
	( 10, uint256("0x6b7d30278fb7436fd9b9839d0334dbb71b6fe28ca524b61259506119dc157431"))
	( 100, uint256("0x74f354db754fa6d05d9dd7045bc85d1c5f47abb5966c97dbd0b46d1eb4a701a2"))
	( 1000, uint256("0x4ef62d44b31d19fdf438e8c041c12b3ed925f865f2ef1aacbb95e265bf27eed8"))
	( 5000, uint256("0xbfdf82b89320a8a0593b3159a478aa311221bc3d171ce57660413b44eebf9bdb"))
	( 9000, uint256("0xe4e8c57f38ca07785dde94f6e2aceda448e68f946f5c06fe9a8d77d72ec34e85"))
	( 10000, uint256("0x97f451f00a8fbdda19e16966372ee7b8355dc31ab3e236921ba91599280f5a30"))
	( 12000, uint256("0xae8a573ea6422de482bea22d8a58440ab5d3ee4ff9a370258e5dc357b1227b86"))
	( 14000, uint256("0xb1622613ba4a641cd0bb65846f397cd7356f3c5e4177b940fcd85bfe438afc12"))
	( 24000, uint256("0x37f549fddf35dddec1136b992dc4eaf8ebf5dd3191004f5f6ca3666b62e88635"))
		;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
		// return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
	
        return mapCheckpoints.rbegin()->first;
		// return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
				// return NULL;
        }
        return NULL;
    }
}
