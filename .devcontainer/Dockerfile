FROM debian:bookworm

USER root
# Update package list and install required packages
RUN apt-get update && \
    apt-get install -y \
    bash \
    git \
    build-essential \
    pkgconf \
    plantuml \
    clang \
    file \
    zsh \
    zsh-syntax-highlighting \
    zsh-autosuggestions \
    curl \
    unzip \
    sudo \
    software-properties-common 
    
RUN <<EOF
    echo 'root:Docker2025' | chpasswd
    # echo 'Docker!\nDocker!' | passwd root 

    groupadd --gid 1000 devcontainer
    useradd --uid 1000 --gid 1000 --groups sudo --shell /bin/zsh --create-home devcontainer

    add-apt-repository -y -U http://deb.debian.org/debian -c non-free-firmware -c non-free -c contrib 
    !!
EOF

USER devcontainer
# Install oh-my-zsh and oh-my-posh
RUN << EOF 
    sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" --unattended
    curl -s https://ohmyposh.dev/install.sh | bash -s
EOF
# Copy the .zshrc configuration file
COPY <<'EOF' /home/devcontainer/.zshrc
    export ZSH=$HOME/.oh-my-zsh
    ZSH_THEME="random"
    plugins=(git)
    source $ZSH/oh-my-zsh.sh
    source /usr/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
    source /usr/share/zsh-autosuggestions/zsh-autosuggestions.zsh
EOF

COPY << 'EOF' /home/devcontainer/.bashrc
    export PATH=$PATH:~/.local/bin/
    THEME_DIR="$HOME/.cache/oh-my-posh/themes"
    # Pick a random theme
    RANDOM_THEME=$(find "$THEME_DIR" -name "*.omp.json" | shuf -n 1)
    # Apply it
    eval "$(oh-my-posh init bash --config "$RANDOM_THEME")"
EOF

# Set the default shell to zsh
CMD ["zsh"]
