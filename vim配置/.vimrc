"auto reload .vimrc when changed, this avoids reopening vim
autocmd! bufwritepost .vimrc source %

set nocompatible              " be iMproved, required
filetype on                   " required
let Tlist_Ctags_Cmd = '/usr/local/bin/ctags'

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'gmarik/Vundle.vim'

" Plugins to be managed by Vundle
" ----------------------------------------------------------
"Plugin 'edkolev/promptline.vim'
Plugin 'tomasr/molokai'
Plugin 'scrooloose/nerdtree'
Plugin 'tpope/vim-markdown'
Plugin 'suan/vim-instant-markdown'
Plugin 'bronson/vim-trailing-whitespace'
Plugin 'kien/rainbow_parentheses.vim'
Plugin 'bling/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
Plugin 'ervandew/supertab'
Plugin 'Raimondi/delimitMate'
Plugin 'scrooloose/syntastic'
Plugin 'scrooloose/nerdcommenter'
Plugin 'godlygeek/tabular'
Plugin 'MatlabFilesEdition'
"Bundle 'Valloric/YouCompleteMe'
Bundle 'Valloric/ListToggle'
Bundle 'SirVer/ultisnips'
Plugin 'honza/vim-snippets'
Bundle 'terryma/vim-multiple-cursors'
Bundle 'hdima/python-syntax'
Bundle 'majutsushi/tagbar'
Bundle 'vim-scripts/taglist.vim'
" ------------------------------------------------------------
"
" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line


" set UTF-8 encoding
set enc=utf-8
set fenc=utf-8
set termencoding=utf-8
set backspace=indent,eol,start
" disable vi compatibility (emulation of old bugs)
set nocompatible

" commenting
set comments=sl:/*,mb:\ *,elx:\ */
set wildmode=longest:full
set wildmenu
set t_Co=256

syntax on

"tabs and spaces
set shiftwidth=4	"1 tab == 2 spaces
set tabstop=4		"<TAB> == 2 spaces
set softtabstop=4	"<TAB> and backspace
set smarttab		"smart tab
set autoindent		"set auto indent
set smartindent		"set smart indent
set copyindent		"use exisiting indents for new indents
set preserveindent	"save as much indent structure as possible

"UI Config
set number			"line number
set showmatch		"highlight matching [({})]
set mat=2			"for showmatch, set how many tenth of second it blinks
set ruler			"show current position
set magic			"magic for regular expression
set confirm			"ask to save file
set showcmd			"display incomplete command in the lower right corner of the console
set undolevels=1000	"let vim allow 1000 undos
set textwidth=80
" do not work in hammer. Uncomment for those not on hammer server
" set colorcolumn=80
" highlight ColorColumn ctermbg=236

"Searching
set incsearch			   "search as char are entered
set hlsearch			   "highlight matches
set smartcase			   "smart with case search

"Folding
set foldenable	      "enable folds
set foldlevelstart=10 "prevent too many folds
set foldmethod=indent "set fold based on indentation
"can also be marker, manual, expr, syntax, or diff
"check :help for more information

"instant markdown
filetype plugin on          "required

"*****************************************************
"rainbow parens                                      *
"*****************************************************
"rainbow parens
au VimEnter * RainbowParenthesesToggle
au Syntax * RainbowParenthesesLoadRound
au Syntax * RainbowParenthesesLoadSquare
au Syntax * RainbowParenthesesLoadBraces
let g:rbpt_colorpairs = [
    \ ['brown',       'RoyalBlue3'],
    \ ['Darkblue',    'SeaGreen3'],
    \ ['darkgray',    'DarkOrchid3'],
    \ ['darkgreen',   'firebrick3'],
    \ ['darkcyan',    'RoyalBlue3'],
    \ ['darkred',     'SeaGreen3'],
    \ ['darkmagenta', 'DarkOrchid3'],
    \ ['brown',       'firebrick3'],
    \ ['gray',        'RoyalBlue3'],
    \ ['black',       'SeaGreen3'],
    \ ['darkmagenta', 'DarkOrchid3'],
    \ ['Darkblue',    'firebrick3'],
    \ ['darkgreen',   'RoyalBlue3'],
    \ ['darkcyan',    'SeaGreen3'],
    \ ['darkred',     'DarkOrchid3'],
    \ ['red',         'firebrick3'],
    \ ]
let g:rbpt_max = 40
let g:rbpt_loadcmd_toggle = 0

"*****************************************************
"indenting                                           *
"*****************************************************
"set list lcs=tab:\¦\ 
" 显示tab和空格
set list
" 设置tab和空格样式
set lcs=tab:\¦\ ,nbsp:%,trail:-
" 设定行首tab为灰色
highlight LeaderTab guifg=#666666
" 匹配行首tab
match LeaderTab /^\t/
"*****************************************************
"statusline                                          *
"*****************************************************
" statusline
set laststatus=2

"*****************************************************
"airline UI                                          *
"*****************************************************
" airline UI
let g:airline#extensions#tabline#enabled = 1
let g:airline_powerline_fonts = 1
let g:airline_theme='tomorrow'

"*****************************************************
"separators                                          *
"*****************************************************
" separators
let g:airline#extensions#tabline#left_sep = '▶'
let g:airline#extensions#tabline#left_alt_sep = '▶'
let g:airline#extensions#tabline#right_sep = '◀'
let g:airline#extensions#tabline#right_alt_sep = '◀'
let g:airline_left_sep = '▶'
let g:airline_left_alt_sep = '▶'
let g:airline_right_sep = '◀'
let g:airline_right_alt_sep = '◀'
"let g:airline_symbols.branch = '▶'
"let g:airline_symbols.readonly = '▶'
"let g:airline_symbols.linenr = '▶'

function! AirlineInit()
	let g:airline_section_a = airline#section#create(['mode',' ','branch'])
	let g:airline_section_b = airline#section#create_left(['%F'])
	let g:airline_section_c = airline#section#create(['ffenc',' ','[%Y]'])
	let g:airline_section_x = airline#section#create(['%P'])   "P
	let g:airline_section_y = airline#section#create(['row:%l/%L ','(%03p%%)'])
	let g:airline_section_z = airline#section#create_right(['col:%03c'])
endfunction
autocmd VimEnter * call AirlineInit()

"*****************************************************
"NERDTree                                            *
"*****************************************************
" autocmd vimenter * NERDTree
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 0 && !exists("s:std_in") | NERDTree | endif
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTreeType") && b:NERDTreeType == "primary")
map <C-t> :NERDTreeToggle<CR>
"*****************************************************
"vim-markdown                                        *
"*****************************************************
autocmd BufNewFile,BufReadPost *.md set filetype=markdown    " *.md support

"*****************************************************
"spell                                               *
"*****************************************************
"map <C-a> :set spell! <CR>
:nnoremap <C-a> :set spell!<CR>

" automatic Whitespace removal
autocmd VimEnter,BufReadPost,bufwritepost,bufenter * :FixWhitespace
"*****************************************************
"malokai theme                                       *
"*****************************************************
let g:molokai_original = 1
let g:rehash256 = 1
colorscheme molokai

"*****************************************************
"YouCompleteMe                                       *
"*****************************************************
"leader映射为逗号“，”
let mapleader = ","
"youcompleteme  默认tab  s-tab 和自动补全冲突
"let g:ycm_key_list_select_completion=['<c-n>']
let g:ycm_key_list_select_completion = ['<Down>']
"let g:ycm_key_list_previous_completion=['<c-p>']
let g:ycm_key_list_previous_completion = ['<Up>']
"配置默认的ycm_extra_conf.py
let g:ycm_global_ycm_extra_conf = '~/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
"打开vim时不再询问是否加载ycm_extra_conf.py配置
let g:ycm_confirm_extra_conf=0
"使用ctags生成的tags文件
let g:ycm_collect_identifiers_from_tag_files = 1
map <F4> : YcmDiags<CR>
nnoremap <silent>gl :YcmCompleter GoToDeclaration<CR>
nnoremap <silent>gf :YcmCompleter GoToDefinition<CR>
"nnoremap <leader>gg :YcmCompleter GoToDefinitionElseDeclaration<CR>
"按gb 会跳转到定义
nnoremap <silent>gb :YcmCompleter GoToDefinitionElseDeclaration<CR>
let g:ycm_goto_buffer_command = 'horizontal-split'
"*****************************************************
"Syntastic                                           *
"*****************************************************
let g:syntastic_error_symbol = '✗'	"set error or warning signs
let g:syntastic_warning_symbol = '⚠'
let g:syntastic_check_on_open=1
let g:syntastic_enable_highlighting = 0
"let g:syntastic_python_checker="flake8,pyflakes,pep8,pylint"
let g:syntastic_python_checkers=['pyflakes']
"highlight SyntasticErrorSign guifg=white guibg=black

let g:syntastic_cpp_include_dirs = ['/usr/include/']
let g:syntastic_cpp_remove_include_errors = 1
let g:syntastic_cpp_check_header = 1
let g:syntastic_cpp_compiler = 'clang++'
let g:syntastic_cpp_compiler_options = '-std=c++11 -stdlib=libstdc++'
let g:syntastic_enable_balloons = 1	"whether to show balloons
"*****************************************************
"C，C++ 按F5编译运行                                 *
"*****************************************************
map <F5> :call CompileRunGcc()<CR>
func! CompileRunGcc()
    exec "w"
    if &filetype == 'c'
        exec "!gcc % -o %<"
        exec "! ./%<"
    elseif &filetype == 'cpp'
        exec "!g++ -std=c++11 % -o %<"
        exec "! ./%<"
    elseif &filetype == 'java'
        exec "!javac %"
        exec "!java %<"
    elseif &filetype == 'sh'
        :!./%
    endif
endfunc
"*****************************************************
"C,C++的调试 F8                                      *
"*****************************************************
map <F8> :call Rungdb()<CR>
func! Rungdb()
    exec "w"
    exec "!g++ -std=c++11 % -g -o %<"
    exec "!cgdb ./%<"
endfunc
"*****************************************************
"UltiSnips                                           *
"*****************************************************
let g:UltiSnipsExpandTrigger = "<tab>"
let g:UltiSnipsJumpForwardTrigger = "<tab>"
let g:UltiSnipsJumpBackwardTrigger="<s-tab>"
"定义存放代码片段的文件夹 .vim/snippets下，使用自定义和默认的，将会的到全局，有冲突的会提示
"let g:UltiSnipsSnippetDirectories=["snippets", "bundle/ultisnips/UltiSnips"]
"*****************************************************
"gao liang dang qian hang                            *
"*****************************************************
set cursorline
hi CursorLine  cterm=NONE   ctermbg=darkred ctermfg=white
hi CursorColumn cterm=NONE ctermbg=darkred ctermfg=white
"*****************************************************
"nerdcommenter                                       *
"*****************************************************
let mapleader=","
let NERDSpaceDelims = 1
"*****************************************************
"vim-multiple-cursors                                *
"*****************************************************
let g:multi_cursor_use_default_mapping=0
" Default mapping
let g:multi_cursor_next_key='<C-m>'
let g:multi_cursor_prev_key='<C-p>'
let g:multi_cursor_skip_key='<C-x>'
let g:multi_cursor_quit_key='<Esc>'
"*****************************************************
"python-syntax                                       *
"*****************************************************
let python_highlight_all = 1
"*****************************************************
"Tagbar                                              *
"*****************************************************
nmap <silent>tb :TagbarToggle<CR>  " \tb 打开tagbar窗口
let g:tagbar_autofocus = 1
"*****************************************************
"Taglist                                             *
"*****************************************************
" \tl                 打开Taglist/TxtBrowser窗口，在右侧栏显示
nmap <silent>tl :Tlist<CR><c-l>
" :Tlist              调用TagList
let Tlist_Show_One_File        = 1             " 只显示当前文件的tags
let Tlist_Exit_OnlyWindow      = 1             " 如果Taglist窗口是最后一个窗口则退出Vim
let Tlist_Use_Right_Window     = 1             " 在右侧窗口中显示
let Tlist_File_Fold_Auto_Close = 1             " 自动折叠
"let Tlist_Sort_Type = "name"                   " items in tags sorted by name
"*****************************************************
"kuo hao gao liang pi pei                            *
"*****************************************************
let g:rbpt_colorpairs = [
    \ ['brown',       'RoyalBlue3'],
    \ ['Darkblue',    'SeaGreen3'],
    \ ['darkgray',    'DarkOrchid3'],
    \ ['darkgreen',   'firebrick3'],
    \ ['darkcyan',    'RoyalBlue3'],
    \ ['darkred',     'SeaGreen3'],
    \ ['darkmagenta', 'DarkOrchid3'],
    \ ['brown',       'firebrick3'],
    \ ['gray',        'RoyalBlue3'],
    \ ['black',       'SeaGreen3'],
    \ ['darkmagenta', 'DarkOrchid3'],
    \ ['Darkblue',    'firebrick3'],
    \ ['darkgreen',   'RoyalBlue3'],
    \ ['darkcyan',    'SeaGreen3'],
    \ ['darkred',     'DarkOrchid3'],
    \ ['red',         'firebrick3'],
    \ ]
let g:rbpt_max = 40
let g:rbpt_loadcmd_toggle = 0
"*****************************************************
"zhu shi tou                                         *
"*****************************************************
autocmd BufNewFile *.py,*.cpp,*.sh,*.java exec ":call SetTitle()"
"新建.py,.cc,.java,.sh,
""定义函数SetTitle，自动插入文件头
func SetTitle()
        if &filetype == 'python'
                call setline(1, "\#!/usr/bin python")
                call setline(2, "\# -*- coding=utf8 -*-")
                call setline(3, "\"\"\"")
                call setline(4, "\# Author: bluarry")
                call setline(5, "\# Created Time : ".strftime("%c"))
                call setline(6, "")
                call setline(7, "\# File Name: ".expand("%"))
                call setline(8, "\# Description:")
                call setline(9, "")
                call setline(10, "\"\"\"")
                call setline(11,"")
        endif
        if &filetype == 'bash'
                call setline(1, "\#!/bin/bash")
                call setline(2, "\# -*- coding=utf8 -*-")
                call setline(3, "\"\"\"")
                call setline(4, "\# Author: bluarry")
                call setline(5, "\# Created Time : ".strftime("%c"))
                call setline(6, "")
                call setline(7, "\# File Name: ".expand("%"))
                call setline(8, "\# Description:")
                call setline(9, "")
                call setline(10, "\"\"\"")
                call setline(11,"")
		endif
        if &filetype == 'cpp'
                call setline(1, "/**")
                call setline(2, "\ *   @Author: bluarry")
                call setline(3, "\ *   @Created Time : ".strftime("%c"))
                call setline(4, "\ *")
                call setline(5, "\ *   @File Name: ".expand("%"))
                call setline(6, "\ *   @Description:")
                call setline(7, "\**/")
                call setline(8,"")
                call setline(9,"\#include<iostream>")
                call setline(10,"\#include<vector>")
                call setline(11,"\#include<deque>")
                call setline(12,"\#include<string>")
                call setline(13,"\#include<set>")
                call setline(14,"\#include<map>")
                call setline(15,"\#include<queue>")
                call setline(16,"\#include<list>")
                call setline(17,"\#include<stack>")
                call setline(18,"\#include<algorithm>")
                call setline(19,"\#include<cstdio>")
                call setline(20,"using namespace std;")
        endif
endfunc

" modify the last modified time of a file
function SetLastModifiedTime(lineno)
        let modif_time = strftime("%c")
        if a:lineno == "-1"
                let line = getline(4)
        else
                let line = getline(a:lineno)
        endif
        if line =~ '^////\sLast Modified'
                let line = substitute( line,':\s\+.*\d\{4\}', ':'.modif_time, "" )
        else
                let line = ' *   @Last Modified: '.modif_time
        endif
        if a:lineno == "-1"
                call setline(4, line)
        else
                call append(a:lineno, line)
        endif
endfunction

" map the SetLastModifiedTime command automatically
au BufWrite *.py,*.cpp,*.sh call SetLastModifiedTime(-1)
"  背景透明
"  hi Normal  ctermfg=252 ctermbg=none
