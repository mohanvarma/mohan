;;(require 'color-theme)
;;(color-theme-initialize)
;;(color-theme-tangotango)

(add-to-list 'load-path "~/.emacs.d/emacs-color-theme-solarized")
(if
    (equal 0 (string-match "^24" emacs-version))
    ;; it's emacs24, so use built-in theme 
    (require 'solarized-dark-theme)
  ;; it's NOT emacs24, so use color-theme
  (progn
    (require 'color-theme)
    (color-theme-initialize)
    (require 'color-theme-solarized)
    (color-theme-solarized-dark)))
;; (load-theme 'solarized-dark t)
;; (require 'auto-complete)
;; (global-auto-complete-mode)

;; turn on font lock with maximum decoration
(global-font-lock-mode t)
(setq font-lock-maximum-decoration t)

(require 'font-lock)
(set-default-font "Ubuntu Mono-12")

;; DodgerBlue2
;; list-colors-display
;; create a face for function calls
(defface font-lock-function-call-face
  '((t (:foreground "LimeGreen")))
  "Font Lock mode face used to highlight function calls."
  :group 'font-lock-highlighting-faces)
(defvar font-lock-function-call-face 'font-lock-function-call-face)

;; add it to the font lock tables
(add-hook 'c-mode-hook
          (lambda ()
            (font-lock-add-keywords
             nil
             '(("\\<\\(\\sw+\\) ?(" 1 font-lock-function-call-face)) t)))
(global-set-key "\C-m" 'newline-and-indent)

(setq-default py-indent-offset 4)
(add-hook 'python-mode-hook
          (lambda ()
            (font-lock-add-keywords
             nil
             '(("\\<\\(\\sw+\\) ?(" 1 font-lock-function-call-face)) t)))

(add-hook 'c++-mode-hook
          (lambda ()
            (font-lock-add-keywords
             nil
             '(("\\<\\(\\sw+\\) ?(" 1 font-lock-function-call-face)) t)))

(add-hook 'java-mode-hook
          (lambda ()
            (font-lock-add-keywords
             nil
             '(("\\<\\(\\sw+\\) ?(" 1 font-lock-function-call-face)) t)))

