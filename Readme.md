### Setup & Installation

-[Zephyr RTOS](https://docs.zephyrproject.org/latest/develop/getting_started/index.html)

```
sudo apt install python3-venv
python3 -m venv ./.venv
source .venv/bin/activate
pip install west
west init .
west update
west zephyr-export
west packages pip --install
cd zephyr
west sdk install
```

-[GitHub Keygen](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent)

```
ssh-keygen -t ed25519 -C "dan.sweeney90@gmail.com"
```