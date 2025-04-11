FROM alpine:3.21
RUN apk update --no-cache && \
    apk add --no-cache \
    bash \
    git \
    build-base \
    fmt-dev \
    pkgconf \
    plantuml \
    clang \
    clang-extra-tools \
    file \
    zsh \
    oh-my-zsh \
    zsh-autosuggestions \
    zsh-syntax-highlighting \
    zsh-vcs
COPY <<'EOF' /root/.zshrc
    export ZSH=/usr/share/oh-my-zsh
    # ZSH_THEME="robbyrussell"
    ZSH_THEME="random"
    plugins=(git)
    source $ZSH/oh-my-zsh.sh
    source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
    source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh
EOF
CMD ["zsh"]
