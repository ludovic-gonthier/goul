<?hh // strict

namespace Goul\Http;

use Psr\Http\Message\UriInterface;

/**
 * {@inheritdoc}
 */
class Uri implements UriInterface
{
    private string $authority = '';
    private string $fragment = '';
    private string $host = '';
    private string $path = '';
    private ?int $port = null;
    private string $query = '';
    private string $scheme = '';
    private string $userInfo = '';

    public function __construct(string $uri)
    {
        $parsed = parse_url($uri);
        if ($parsed === false) {
            throw new \DomainException();
        }

        if (array_key_exists('fragment', $parsed)) {
            $this->fragment = $parsed['fragment'];
        }
        if (array_key_exists('host', $parsed)) {
            $this->host = $parsed['host'];
            $this->authority = $this->host;
        }
        if (array_key_exists('path', $parsed)) {
            $this->path = $parsed['path'];
        }
        if (array_key_exists('port', $parsed)) {
            $this->port = $parsed['port'];
            if ($this->authority !== '') {
                $this->authority .= ':' . $this->port;
            }
        }
        if (array_key_exists('query', $parsed)) {
            $this->query = $parsed['query'];
        }
        if (array_key_exists('scheme', $parsed)) {
            $this->scheme = $parsed['scheme'];
        }
        if (array_key_exists('user', $parsed)) {
            $this->userInfo = $parsed['user'];

            if (array_key_exists('pass', $parsed)) {
                $this->userInfo .= ':' . $parsed['pass'];
            }

            if ($this->authority !== '') {
                $this->authority = $this->userInfo . '@' . $this->authority;
            }
        }
    }

    /**
     * {@inheritdoc}
     */
    public function getScheme(): string
    {
        return $this->scheme;
    }

    /**
     * {@inheritdoc}
     */
    public function getAuthority(): string
    {
        return $this->authority;
    }

    /**
     * {@inheritdoc}
     */
    public function getUserInfo(): string
    {
        return $this->userInfo;
    }

    /**
     * {@inheritdoc}
     */
    public function getHost(): string
    {
        return $this->host;
    }

    /**
     * {@inheritdoc}
     */
    public function getPort(): ?int
    {
        return $this->port;
    }

    /**
     * {@inheritdoc}
     */
    public function getPath(): string
    {
        return $this->path;
    }

    /**
     * {@inheritdoc}
     */
    public function getQuery(): string
    {
        return $this->query;
    }

    /**
     * {@inheritdoc}
     */
    public function getFragment(): string
    {
        return $this->fragment;
    }

    /**
     * {@inheritdoc}
     */
    public function withScheme(string $scheme): UriInterface
    {
        $uri = clone $this;
        $uri->scheme = $scheme;

        return $uri;
    }

    /**
     * {@inheritdoc}
     */
    public function withUserInfo(string $user, ?string $password = null): UriInterface
    {
        $uri = clone $this;
        $uri->userInfo = $user;

        if ($password !== null) {
            $uri->userInfo .= ':' . $password;
        }

        return $uri;
    }

    /**
     * {@inheritdoc}
     */
    public function withHost(string $host): UriInterface
    {
        $uri = clone $this;
        $uri->host = $host;

        return $uri;
    }

    /**
     * {@inheritdoc}
     */
    public function withPort(?int $port): UriInterface
    {
        $uri = clone $this;
        $uri->port = $port;

        return $uri;
    }

    /**
     * {@inheritdoc}
     */
    public function withPath(string $path): UriInterface
    {
        $uri = clone $this;
        $uri->path = $path;

        return $uri;
    }

    /**
     * {@inheritdoc}
     */
    public function withQuery(string $query): UriInterface
    {
        $uri = clone $this;
        $uri->query = $query;

        return $uri;
    }

    /**
     * {@inheritdoc}
     */
    public function withFragment(string $fragment): UriInterface
    {
        $uri = clone $this;
        $uri->fragment = $fragment;

        return $uri;
    }

    /**
     * {@inheritdoc}
     */
    public function __toString(): string
    {
        $uri = '';

        if ($this->scheme !== '') {
            $uri .= $this->scheme . ':';
        }

        if ($this->authority !== '') {
            $uri .= '//' . $this->authority;
        }

        if ($this->query !== '') {
            $uri .= '?' . $this->query;
        }

        if ($this->authority !== '' && strpos('/', $this->path) !== 0) {
            $uri .= '/';
        }

        if ($this->authority === '' && strpos('//', $this->path) !== 0) {
            $uri .= ltrim($this->path, '/');
        } else {
            $uri .= $this->path;
        }

        if ($this->fragment !== '') {
            $uri .= '#' . $this->fragment;
        }

        return $uri;
    }
}
