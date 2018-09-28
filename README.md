# JAGS rescorlaWagner module

The JAGS rescorlaWagner module is an extension for JAGS that implements the
[Rescorla-Wagner model](https://en.wikipedia.org/wiki/Rescorla%E2%80%93Wagner_model)
applied to the two-choice [bandit problem](https://en.wikipedia.org/wiki/Multi-armed_bandit).

## JAGS function

`resWagner` returns a vector of probabilities of choosing A or B based on the
Rescorla-Wagner model.

#### Usage
```R
theta <- resWagner(choice, reward, va0, vb0, a, beta)
```

#### Arguments
|     |     |
| --- | --- |
| **choice** | a vector that contains the subjects choices for a particular two-choice problem, where choosing stimulus `A` is coded as **0** and choosing stimulus `B` is coded as **1** |
| **reward** | a vector that contains whether a choice was correct (coded as **1**) or incorrect (coded as **0**) |
| **va0** | a scalar defining the starting value for the change in strength parameter of stimulus `A`. Has to be between 0 and 1. |
| **vb0** | a scalar defining the starting value for the change in strength parameter of stimulus `B`. Has to be between 0 and 1. |
| **a** | a scalar defining the rate with which the strength of the association changes per any given trial. Has to be between 0 and 1. |
| **beta** |  a scalar rescaling the theta outcome variable so that it can take on values between 0 and 1. Also called [softmax](https://hannekedenouden.ruhosting.nl/RLtutorial/html/SoftMax.html). |


##### Output
|     |     |
| --- | --- |
| **theta** | a vector containing the probabilities of choosing stimulus A (theta close to 0), or stimulus B (theta close to 1) |


## Build instructions

### Linux and MacOS

#### From tarball

Download the [tarball](https://github.com/raviselker/jags-rescorlaWagner/releases/download/v0.9.0/JAGS-RESCORLAWAGNER-MODULE-0.9.0.tar.gz), extract it, and open a terminal.

```sh
# change the working directory
cd path/to/jags-rescorlaWagner

sudo ./configure && sudo make && sudo make install
```
Note: It might be necessary to define a different prefix, depending on where JAGS is copied (i.e. installed), for example:
```sh
sudo ./configure --prefix /usr && sudo make && sudo make install
```

#### From repository

Download or clone this repository on your computer and open a terminal.

```sh
# change the working directory
cd path/to/jags-rescorlaWagner

# dependencies (on a clean ubuntu installation)
sudo apt-get install autoconf automake libtool g++

# creating all auxiliary files
autoreconf -fvi

# building
sudo ./configure
sudo make

# or, if JAGS has been installed in a different location, e.g. /usr
sudo ./configure --prefix /usr
sudo make

# install
sudo make install
```
