;; .emacs

(custom-set-variables
 ;; uncomment to always end a file with a newline
 ;'(require-final-newline t)
 ;; uncomment to disable loading of "default.el" at startup
 ;'(inhibit-default-init t)
 ;; default to unified diffs
 '(diff-switches "-u"))

;; setting font
(set-face-attribute 'default nil :font "Monaco-10")

;; map enter with newline and indent to auto indent
(global-set-key "\C-m" 'newline-and-indent)

;;; uncomment for CJK utf-8 support for non-Asian users
;; (require 'un-define)
;; setting colortheme
(require 'color-theme)
     (color-theme-select)
        (color-theme-tangotango)

(setq-default py-indent-offset 4)
    (add-hook 'python-mode-hook '(lambda () (define-key python-mode-map "\C-m" 'newline-and-indent)))
    (set-face-attribute 'default nil :height 100)

;; Highlight function calls in c mode
;;
;; turn on font lock with maximum decoration
(global-font-lock-mode t)
(setq font-lock-maximum-decoration t)

(require 'font-lock)

;; create a face for function calls
(defface font-lock-function-call-face
  '((t (:foreground "SpringGreen")))
  "Font Lock mode face used to highlight function calls."
  :group 'font-lock-highlighting-faces)
(defvar font-lock-function-call-face 'font-lock-function-call-face)

;; add it to the font lock tables
(add-hook 'c-mode-hook
          (lambda ()
            (font-lock-add-keywords
             nil
             '(("\\<\\(\\sw+\\) ?(" 1 font-lock-function-call-face)) t)))

(add-hook 'c++-mode-hook
          (lambda ()
            (font-lock-add-keywords
             nil
             '(("\\<\\(\\sw+\\) ?(" 1 font-lock-function-call-face)) t)))

(add-hook 'python-mode-hook
          (lambda ()
            (font-lock-add-keywords
             nil
             '(("\\<\\(\\sw+\\) ?(" 1 font-lock-function-call-face)) t)))
