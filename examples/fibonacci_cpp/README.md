# fibonacci in C++

# Run in dfx

After installation of [Miniconda](https://docs.anaconda.com/miniconda/install/):

```bash
conda create --name canbench python=3.11
conda activate canbench
pip install icpp-pro

icpp build-wasm

dfx start --clean
dfx deploy

dfx canister call fibonacci fibonacci 10
```

# Run in canbench

NOTE: This is under development.
We need to link the canbench experiment code into the wasm.
Currently figuring out how to do that...

```bash
conda create --name canbench python=3.11
conda activate canbench
pip install icpp-pro

icpp build-wasm

canbench
```