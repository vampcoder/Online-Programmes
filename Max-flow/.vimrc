set nocompatible              					" be iMproved, required
filetype off                  					" required

set rtp+=~/.vim/bundle/Vundle.vim                               " set the runtime path to include Vundle and initialize

call vundle#begin()                       			" alternatively, pass a path where Vundle should install plugins
					  			"call vundle#begin('~/some/path/here')
					   			" let Vundle manage Vundle, required
Plugin 'gmarik/Vundle.vim'

					" The following are examples of different formats supported.
					" Keep Plugin commands between vundle#begin/end.
					" plugin on GitHub repo

Plugin 'Raimondi/delimitMate'                         		"Automatically add cosing brackets

"Plugin 'Valloric/YouCompleteMe'                        	"You complete me plugin

Plugin 'scrooloose/nerdtree'               			"file navigator nerd tree


Plugin 'altercation/vim-colors-solarized'

"Plugin 'c.vim'
Plugin 'honza/vim-snippets'

"Plugin 'Valloric/YouCompleteMe'

"Plugin 'garbas/vim-snipmate'


call vundle#end()			" All of your Plugins must be added before the following line            
					" required
filetype plugin indent on    		" required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"N
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

set tabstop=4
set softtabstop=4
set autoindent		"auto indentations
set cindent		"c style indent		
set number 		"line number
set showcmd 		"show command in bottom 
set ruler 		"
set wrap		"line wrap
set ruler		"ruler at bottom
set autoread		"reflect external file changes use :e
set nobackup		"no backup swp
set cb=unnamed		"tabstop
set backspace=2		"backspace settings
set cursorline		"highlight current line
set wildmenu            " visual autocomplete for command menu
set showmatch           " highlight matching [{()}]

set makeprg=g++\ -o\ \"%:p:r\"\ \"%:p\"
map <F9> :w<CR>:!clear<CR>:make<CR>
imap <F9> <ESC>:w<CR>:!clear<CR>:make<CR>
map <F5> :!clear<CR>:!%:p:r<CR>


