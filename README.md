## Dollarcoin 

Abbrevation word: DOLLAR

Abbrevation sign: $

## Website

http://www.edollar.international/

## What is DollarCoin?

Dollarcoin is like Bitcoin, but based on Litecoin.

## License

DollarCoin is released under the terms of the MIT license. See http://opensource.org/licenses/MIT.

## Development and contributions

Developers work in their own trees, then submit pull requests when they think their feature or bug fix is ready.

## Total DOLLAR coins

The total number of DOLLAR coins will be 10 billions.

## Block Time

120 Seconds

## Difficulty Retarget Time

2 hours

## Rewards

Block 1 - 200,000 : 2 DOLLAR Reward

Block 200,001 - 400,000 : 2 - 20 DOLLAR Reward

Block 400,001 - 600,000 : 2 - 30 DOLLAR Reward

Block 600,001 - 800,000 : 2 - 20 DOLLAR Reward

Block 800,001+ : 10 DOLLAR Reward

## Make dollarcoind

    sudo apt-get install build-essential \
                         libssl-dev \
                         libdb5.1++-dev \
                         libboost-all-dev \
                         libqrencode-dev \
                         libminiupnpc-dev

    cd src/
    make -f makefile.unix USE_UPNP=1 USE_IPV6=1 USE_QRCODE=1

## Ports

RPC 11888

P2P 11889
