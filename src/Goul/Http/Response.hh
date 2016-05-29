<?hh // strict

namespace Goul\Http;

use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\StreamInterface;

/**
 * {@inheritdoc}
 */
class Response extends Message implements ResponseInterface
{
    static ImmMap<int, string> $status = ImmMap {
        100	=> 'Continue',
        101	=> 'Switching Protocols',
        102	=> 'Processing',
        200	=> 'OK',
        201	=> 'Created',
        202	=> 'Accepted',
        203	=> 'Non-Authoritative Information',	
        204	=> 'No Content',
        205	=> 'Reset Content',
        206	=> 'Partial Content',
        207	=> 'Multi-Status',
        208	=> 'Already Reported',
        226	=> 'IM Used',
        300	=> 'Multiple Choices',
        301	=> 'Moved Permanently',
        302	=> 'Found',
        303	=> 'See Other',
        304	=> 'Not Modified',
        305	=> 'Use Proxy',
        306	=> '(Unused)',
        307	=> 'Temporary Redirect',
        308	=> 'Permanent Redirect',
        400	=> 'Bad Request',
        401	=> 'Unauthorized',
        402	=> 'Payment Required',
        403	=> 'Forbidden',
        404	=> 'Not Found',
        405	=> 'Method Not Allowed',
        406	=> 'Not Acceptable',
        407	=> 'Proxy Authentication Required',
        408	=> 'Request Timeout',
        409	=> 'Conflict',
        410	=> 'Gone',
        411	=> 'Length Required',
        412	=> 'Precondition Failed',
        413	=> 'Payload Too Large',
        414	=> 'URI Too Long',
        415	=> 'Unsupported Media Type',
        416	=> 'Range Not Satisfiable',
        417	=> 'Expectation Failed',
        421	=> 'Misdirected Request',
        422	=> 'Unprocessable Entity',
        423	=> 'Locked',
        424	=> 'Failed Dependency',
        426	=> 'Upgrade Required',
        428	=> 'Precondition Required',
        429	=> 'Too Many Requests',
        431	=> 'Request Header Fields Too Large',
        451	=> 'Unavailable For Legal Reasons',
        500	=> 'Internal Server Error',
        501	=> 'Not Implemented',
        502	=> 'Bad Gateway',
        503	=> 'Service Unavailable',
        504	=> 'Gateway Timeout',
        505	=> 'HTTP Version Not Supported',
        506	=> 'Variant Also Negotiates',
        507	=> 'Insufficient Storage',
        508	=> 'Loop Detected',
        510	=> 'Not Extended',
        511	=> 'Network Authentication Required',
    };

    private string $reasonPhrase = '';
    private int $statusCode;

    public function __construct(
        StreamInterface $body,
        int $statusCode,
        array<string, array<string>> $headers,
        string $protocolVersion
    ) {
        parent::__construct($body, $headers, $protocolVersion);

        if (self::$status->contains($statusCode) === false) {
            throw new \InvalidArgumentException('');
        }

        $this->statusCode = $statusCode;
        $this->reasonPhrase = self::$status[$statusCode];
    }

    /**
     * {@inheritdoc}
     */
    public function getStatusCode(): int
    {
        return $this->statusCode;
    }

    /**
     * {@inheritdoc}
     */
    public function withStatus(int $code, string $reasonPhrase = ''): this
    {
        if (self::$status->contains($code) === false) {
            throw new \InvalidArgumentException('');
        }

        $response = clone $this;
        $response->statusCode = $code;
        $response->reasonPhrase = self::$status[$code];

        return $response;
    }

    /**
     * {@inheritdoc}
     */
    public function getReasonPhrase(): string
    {
        return $this->reasonPhrase;
    }
}

